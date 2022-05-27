# YahooFinanceCommandLineTool
Windows command line tool I created to download equity time series data from Yahoo Finance. Built using C++ and the CURL library

## How to use

By default using the command `YahooFinanceAPI equityTicker` will give the daily price data from Yahoo Finance wih a range from the past 5 years from today (year to date). Adding a date as the second argument, `YahooFinanceAPI equityTicker mm/dd/yyyy` , will do the same but the date range from the inputed date to day. Adding an additional date as a third argument, `YahooFinanceAPI equityTicker mm/dd/yyyy mm/dd/yyyy`, will use the date range starting from the first date and ending with the last date. When using tickers with symbols such as the S&P500, whose ticker is ^GSPC, use quoatations around it, ex: `"^GSPC"`
If downloaded, the user will be notified, along with the date range downloaded. Otherwise, if an invalid ticker is inputted the user will be notified. Any non date strings in the arugments will also either be converted to unix time or nothing will happen.

## Examples

Using the 5 year option

```
$\YahooFinanceAPI AAPL
Case 1: Retrieving 5 year daily data for AAPL.
Downloaded AAPL.csv successfully!
```

Using the date to today option

```
$\YahooFinanceAPI AAPL 1/1/2022
Case 2: Retrieving daily data for AAPL from the date 1/1/2022 to today.
Downloaded AAPL.csv successfully!
```

Using the custom date range option

```
$\YahooFinanceAPI AAPL 1/1/2022 4/1/2022
Case 3: Retrieving daily data for AAPL from the date range1/1/2022 to 4/1/2022.
Downloaded AAPL.csv successfully!
```

Using a bad ticker

```
$\YahooFinanceAPI fdksafdah
Case 1: Retrieving 5 year daily data for fdksafdah.
Error #22       Ticker 'fdksafdah' does not exist!
```
