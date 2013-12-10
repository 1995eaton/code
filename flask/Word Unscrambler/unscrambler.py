from flask import Flask, request, render_template
import os, re

app = Flask(__name__)

@app.route('/', methods=['GET', 'POST'])
def unscrambleWords():
	if request.method == 'GET':
		return render_template('index.html')
	if request.method == 'POST':
		word = request.form['WORD']
		try:
			dictionary = (open(str("dictionary_segments/" + str(len(word))), "r").read()).rsplit()
		except FileNotFoundError as DNE:
			return render_template('index.html', hist = request.form['hist'])
		word_sorted = sorted(word)
		words_unscrambled = []
		for i in dictionary:
			if len(word) == len(i) and word_sorted == sorted(i):
				words_unscrambled.append(i)
		if len(words_unscrambled) == 0:
			return render_template('index.html', word = "<br/>".join(words_unscrambled), hist = request.form['hist'])
		else:
			return render_template('index.html', word = "<br/>".join(words_unscrambled), hist = "<br/>" + request.form['hist'])

if __name__ == "__main__":
	app.run()