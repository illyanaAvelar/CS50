SELECT DISTINCT people.name
FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id
JOIN stars AS kevin_stars ON kevin_stars.movie_id = movies.id
JOIN people AS kevin_bacon ON kevin_bacon.id = kevin_stars.person_id
WHERE kevin_bacon.name = 'Kevin Bacon'
AND kevin_bacon.birth = 1958
AND people.name != 'Kevin Bacon';
