import requests
import sys

def get_random_words(num):
    url = f"https://random-word-api.herokuapp.com/word?number={num}"
    response = requests.get(url)
    if response.status_code == 200:
        words = response.json()
        return words
    else:
        return None


if len(sys.argv) > 1:
    num_words = sys.argv[1]

else:
    num_words = 1000

words = get_random_words(num_words)

if words:
    words_string = " ".join(words)
    print(words_string)
else:
    print("Failed to fetch random words.")