from flask import Flask, request, render_template
from markupsafe import Markup
import os

app = Flask(__name__)

@app.route('/', methods=['GET', 'POST'])
def unscrambleWords():
	if request.method == 'GET':
		return render_template('index.html')
	if request.method == 'POST':
		anagram_input = ''.join([i for i in request.form['anagram_input'].lower() if i.isalpha()])
		try:
			dictionary = (open(str("dictionary_segments/" + str(len(anagram_input))), "r").read()).rsplit()
		except FileNotFoundError as DNE:
			return render_template('index.html', previous_anagrams = Markup(request.form['previous_anagrams']))
		anagram_sorted = sorted(anagram_input)
		anagram_list = []
		for word in dictionary:
			if len(anagram_input) == len(word) and anagram_sorted == sorted(word):
				anagram_list.append(word)
		if len(anagram_list) == 0:
			#return render_template('index.html', current_anagrams = Markup("<br/>").join(anagram_list), previous_anagrams = Markup(request.form['previous_anagrams']))
			return render_template('index.html', previous_anagrams = Markup(request.form['previous_anagrams']))
		else:
			return render_template('index.html', current_anagrams = Markup("<br/>").join(anagram_list), previous_anagrams = Markup(request.form['previous_anagrams']))

if __name__ == "__main__":
	app.run()
