"""Collection rate for each fog collector -- DRAFT.

Reads every run in data/runs/ named <collector>_run<N>.csv (columns time_s,grams),
finds the first drip, fits a straight line to grams vs minutes after it, and
reports the collection rate in g/min. Then averages the runs for each collector
and draws a bar chart with error bars.

Usage (from the repository root):
    python analysis/collection_rate.py
"""
from pathlib import Path
import re

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

RUNS = Path(__file__).resolve().parent.parent / "data" / "runs"
DRIP_G = 0.5      # the first drip is when the cup has gained this many grams
ORDER = ["mesh", "harp", "hybrid"]


def load_run(path):
    df = pd.read_csv(path, comment="#")
    df = df.rename(columns=str.strip)
    df = df[["time_s", "grams"]].astype(float)
    # zero against the first 10 seconds, in case the tare drifted
    df["grams"] -= df.loc[df["time_s"] <= 10, "grams"].mean()
    return df


def collection_rate(df):
    """Return (first drip time in min, rate in g/min) for one run."""
    wet = df[df["grams"] >= DRIP_G]
    if wet.empty:
        return np.nan, 0.0
    t_first = wet["time_s"].iloc[0] / 60
    after = df[df["time_s"] / 60 >= t_first]
    slope, _ = np.polyfit(after["time_s"] / 60, after["grams"], 1)
    return t_first, slope


def main():
    rows = []
    for path in sorted(RUNS.glob("*_run*.csv")):
        m = re.match(r"(\w+?)_run(\d+)\.csv$", path.name)
        if not m:
            continue
        t_first, rate = collection_rate(load_run(path))
        rows.append({"collector": m.group(1), "run": int(m.group(2)),
                     "first_drip_min": round(t_first, 2), "rate_g_per_min": round(rate, 3)})

    if not rows:
        print(f"No runs found in {RUNS}")
        return

    runs = pd.DataFrame(rows).sort_values(["collector", "run"])
    print(runs.to_string(index=False))

    summary = runs.groupby("collector")["rate_g_per_min"].agg(["mean", "std", "count"])
    summary = summary.reindex([c for c in ORDER if c in summary.index] +
                              [c for c in summary.index if c not in ORDER])
    print()
    print(summary.round(3).to_string())

    fig, ax = plt.subplots(figsize=(5, 4))
    ax.bar(summary.index, summary["mean"], yerr=summary["std"].fillna(0), capsize=6,
           color="#2f7d5c")
    ax.set_ylabel("Collection rate (g/min)")
    ax.set_title("Fog collection rate by collector")
    ax.spines[["top", "right"]].set_visible(False)
    fig.tight_layout()
    out = RUNS.parent / "collection_rate.png"
    fig.savefig(out, dpi=150)
    print(f"\nSaved {out}")


if __name__ == "__main__":
    main()
