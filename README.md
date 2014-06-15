# socket-experiement

I wrote this in an evening when I was curious about how hard it would be to push
data from a small device like a [Spark Core](http://spark.io) to my own custom
web stack for monitoring or other purposes. It turns out it is pretty simple.
There would be a large amount of added complexity if I wanted to read in data,
and I may extend this experiment to include that.

## main.c

A small C application that can push data to http://localhost:8000

## index.js

A small node.js application that outputs what data it recieved to the console.