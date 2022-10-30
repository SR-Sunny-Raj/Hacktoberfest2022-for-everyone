# Content-based-Movie-Recommendation-System

![Python](https://img.shields.io/badge/Python-3.9-lightblue)
![Framework](https://img.shields.io/badge/Framework-Streamlit-red)
![API](https://img.shields.io/badge/API-TMDB-fcba03)
![Deploy](https://img.shields.io/badge/Deploy-Heroku-violet)


# movie-recommender-system
Content-Based Recommender System recommends movies similar to the movie user likes and analyses the sentiments on the reviews given by the user for that movie.

> **_NOTE:_**  The application has been updated to a newer version. Get the source code of the newer version [here](https://github.com/Sumitsah0/movie-recommender-system)

Check out the live demo: https://mrs-sumitsah.herokuapp.com/

The details of the movies(title, genre, runtime, rating, poster, etc) are fetched using an API by [TMDB],(https://www.themoviedb.org/documentation/api) and using the IMDB id of the movie in the API, I did web scraping to get the reviews given by the user in the IMDB site using `streamlit` and performed sentiment analysis on those reviews.

# How to get the API key?
Create an account in https://www.themoviedb.org/, click on the `API` link from the left hand sidebar in your account settings and fill all the details to apply for API key. You will see the API key in your `API` sidebar once your request is approved.

# How to run the project?
Install all the libraries mentioned in the [requirements.txt]() file.
Clone this repository in your local system.
Replace YOUR_API_KEY in the app.py file.
Open the command prompt from your project directory and run the command python app.py.
Go to your browser and type http://localhost:8501/ in the address bar.
Hurray! That's it.

# Similarity Score :
How does it decide which item is most similar to the item user likes? Here we use the similarity scores.

It is a numerical value ranges between zero to one which helps to determine how much two items are similar to each other on a scale of zero to one. This similarity score is obtained measuring the similarity between the text details of both of the items. So, similarity score is the measure of similarity between given text details of two items. This can be done by cosine-similarity.

# How Cosine Similarity works?
Cosine similarity is a metric used to measure how similar the documents are irrespective of their size. Mathematically, it measures the cosine of the angle between two vectors projected in a multi-dimensional space. The cosine similarity is advantageous because even if the two similar documents are far apart by the Euclidean distance (due to the size of the document), chances are they may still be oriented closer together. The smaller the angle, higher the cosine similarity.

![cosine distance](https://user-images.githubusercontent.com/36665975/70401457-a7530680-1a55-11ea-9158-97d4e8515ca4.png)

More about Cosine Similarity :[Understanding the Math behind Cosine Similarity](https://www.machinelearningplus.com/nlp/cosine-similarity/)

## Similarity pkl file
Due to its larger size of >100MB, i couldn't able to upload it. But it the user will run the notebook then you can easily see it on your device destination folder.

# Sources of the datasets
https://www.kaggle.com/datasets/tmdb/tmdb-movie-metadata
