""" You are given  words. Some words may repeat. For each word, output its number of occurrences.
The output order should correspond with the input order of appearance of the word."""

# https://www.hackerrank.com/challenges/word-order/problem?isFullScreen=true

n = int(input().strip())
counter = {}
words = []
for i in range(n):
  word = input().strip()
  if word in counter:
    counter[word] += 1
  else:
    counter[word] = 1
    words.append(word)

print (len(words))
print( ' '.join([str(counter[word]) for word in words]))
