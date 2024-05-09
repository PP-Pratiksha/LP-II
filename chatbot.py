responses = {
    "hello": "Hi there! How can I assist you today?",
    "products": "We have a variety of products available: shoes and clothing.",
    "shoes": "We offer a range of shoes including sneakers, boots, and sandals.",
    "sneakers": "Sneakers are Comfortable shoes for casual wear.",
    "price_sneakers": "Price: 1000 onwards",
    "sizes_sneakers": "Available sizes: 5-11",
    "colors_sneakers": "Available colors: Red, Blue, Black, White",
    "boots": "Boots are Sturdy footwear suitable for various outdoor activities.",
    "price_boots": "Price: 1800 onwards",
    "sizes_boots": "Available sizes: 6-12",
    "colors_boots": "Available colors: Brown, Black, Grey",
    "sandals": "Sandals are Open-toed shoes perfect for warm weather.",
    "price_sandals": "Price: 800 onwards",
    "sizes_sandals": "Available sizes: 4-10",
    "colors_sandals": "Available colors: Brown, Black, Blue",
    "clothing": "Our clothing selection includes shirts, pants, and jackets.",
    "shirts": "Shirts are Various styles and colors available.",
    "price_shirts": "Price: 600 onwards",
    "sizes_shirts": "Available sizes: XS-XXL",
    "colors_shirts": "Available colors: Red, Blue, Green, White",
    "pants": "Pants are Casual and formal options available.",
    "price_pants": "Price: 800 onwards",
    "sizes_pants": "Available sizes: 28-38",
    "colors_pants": "Available colors: Black, Grey, Khaki",
    "jackets": "Jackets are Stay warm with our stylish jackets.",
    "price_jackets": "1000 onwards",
    "sizes_jackets": "Available sizes: S-3XL",
    "colors_jackets": "Available colors: Black, Blue, Green, Brown",
    "bye": "Goodbye! Have a great day!",
    "default": "I'm sorry, I didn't quite understand that."
}

print("Chatbot: Hi! Welcome.")
while True:
    user_input = input("User: ").lower()
    if any(keyword in user_input for keyword in responses):
        for keyword, response in responses.items():
            if keyword in user_input:
                if keyword.startswith("price_") or keyword.startswith("sizes_") or keyword.startswith("colors_"):
                    print("Chatbot:", response)
                elif "price of " + keyword in user_input:
                    product_price_key = "price_" + keyword
                    print("Chatbot:", responses.get(product_price_key, "I'm sorry, I don't have the price for that."))
                elif "sizes of " + keyword in user_input:
                    product_sizes_key = "sizes_" + keyword
                    print("Chatbot:", responses.get(product_sizes_key, "I'm sorry, I don't have the sizes available for that."))
                elif "colors of " + keyword in user_input:
                    product_colors_key = "colors_" + keyword
                    print("Chatbot:", responses.get(product_colors_key, "I'm sorry, I don't have the colors available for that."))
                else:
                    print("Chatbot:", response)
                break
        if "bye" in user_input:
            break
    else:
        print("Chatbot:", responses["default"])
