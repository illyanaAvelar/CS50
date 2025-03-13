SELECT movies.title
FROM movies
JOIN stars AS stars1 ON stars1.movie_id = movies.id
JOIN stars AS stars2 ON stars2.movie_id = movies.id
JOIN people AS person1 ON person1.id = stars1.person_id
JOIN people AS person2 ON person2.id = stars2.person_id
WHERE person1.name = 'Bradley Cooper'
AND person2.name = 'Jennifer Lawrence';
