
import pandas as pd


def load(path: str):
    try:
        data = pd.read_csv(path)
        print("Loading dataset of dimensions", data.shape)
    except Exception as e:
        print(f"AssertionError: {e}")
        return
    return data
