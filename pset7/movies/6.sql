SELECT AVG(rating)
from ratings
JOIN movies ON ratings.movie_id = movies.id
WHERE year = 2012;
