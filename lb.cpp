import requests  # Для виконання HTTP-запитів
from deep_translator import GoogleTranslator  # Для перекладу тексту

# Отримуємо випадкову цитату з API
response = requests.get("https://api.breakingbadquotes.xyz/v1/quotes")
data = response.json()

# Виділяємо текст цитати та автора
quote = data[0]["quote"]
author = data[0]["author"]

# Перекладаємо цитату на українську
translated_quote = GoogleTranslator(source="en", target="uk").translate(quote)

# Виводимо результат у консоль
print(f'"{translated_quote}" - {author}')

# Зберігаємо у файл
with open("quote.txt", "w", encoding="utf-8") as file:
    file.write(f'"{translated_quote}" - {author}')
