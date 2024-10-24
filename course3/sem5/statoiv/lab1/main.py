import pandas as pd
import re

def is_number(value):
    if isinstance(value, str):
        return bool(re.match(r'^-?\d+(\.\d+)?$', value))
    return False

def main():
    pd.set_option('display.max_columns', None)
    dataset = pd.read_csv("winemag-data-130k-v2.csv")

    dataset.rename(columns={'Unnamed: 0': 'index'}, inplace=True)

    for index, row in dataset.iterrows():
        for col in dataset.columns:
            value = row[col]
            if is_number(value):
                dataset.at[index, col] = pd.to_numeric(value, errors='ignore')

    dataset.dropna(inplace=True)
    dataset.drop(columns=['designation', 'region_2', 'taster_twitter_handle'], inplace=True)
    
    dataset.reset_index(drop=True, inplace=True)
    dataset['index'] = dataset.index 

    description = dataset.describe()
    print("Описание набора данных:\n", description)

    dataset.to_csv("winemag_processed.csv", index=False)

if __name__ == '__main__':
    main()