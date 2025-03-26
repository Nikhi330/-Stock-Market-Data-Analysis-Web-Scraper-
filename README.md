# -Stock-Market-Data-Analysis-Web-Scraper-

To check if your C++ web scraper works correctly, follow these steps:

1. Install Dependencies
Make sure you have libcurl and RapidJSON installed.

For Ubuntu/Linux:
sudo apt update
'sudo apt install libcurl4-openssl-dev'

Download RapidJSON:
git clone https://github.com/Tencent/rapidjson.git
Then, move the rapidjson/include directory to your project folder.

For Windows (MinGW/Visual Studio):
Install libcurl from cURL official site.
Download RapidJSON.

2. Compile the Code
Use g++ to compile the C++ file:
g++ -o stock_scraper stock_scraper.cpp -lcurl

If using RapidJSON separately, include the include path:
g++ -o stock_scraper stock_scraper.cpp -Irapidjson/include -lcurl

4. Run the Program
Execute the compiled binary:
'./stock_scraper'
If everything is set up correctly, it should fetch and display stock data.

4. Debugging & Testing
If you get an error:
Check the API URL: The default API in the code (https://api.example.com/...) is fake. Replace it with a real API like:
1.Alpha Vantage
2.Yahoo Finance

Check Internet Connection: The scraper needs internet access to fetch data.
