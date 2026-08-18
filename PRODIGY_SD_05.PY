import requests
from bs4 import BeautifulSoup
import csv

# Random URL to perform Scraping
URL = 'https://books.toscrape.com/'

# Sending get request to webbsite
response = requests.get(URL)

#Checking wheather the request was successful or not
response.raise_for_status() 

# Performing Parsing to the content
soup = BeautifulSoup(response.text, 'html.parser')

# Searching for right place where the information is stored
Scraped = soup.find_all('article', class_='product_pod')

# Writing the information of the product to a CSV file
with open('Scraped.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(['Name', 'Price', 'Rating'])

    # Iterating through the file and extracting information
    for product in Scraped:
        # product name
        name = product.h3.a['title']

        # product price
        price = product.find('p', class_='price_color').text

        # product rating
        rating_class = product.p['class']
        rating = [r for r in rating_class if r != 'star-rating'][0]

        # Writing product information to the CSV file
        writer.writerow([name, price, rating])

print('Product information has been saved to Scraped.csv')