.read hw10_data.sql

-- The size of each dog
CREATE TABLE size_of_dogs AS
  SELECT name, size FROM dogs, sizes WHERE sizes.min < dogs.height AND dogs.height <= sizes.max;

-- All dogs with parents ordered by decreasing height of their parent
CREATE TABLE by_parent_height AS
  SELECT child AS name FROM parents, dogs WHERE parents.parent = dogs.name ORDER BY dogs.height DESC;


-- Sentences about siblings that are the same size
--    SELECT "The two siblings, " || child || " plus " || name || " have the same size: " || size FROM parents, dogs, sizes WHERE  min < height AND height <= max;
CREATE TABLE sentences AS
    SELECT "The two siblings, " || a.child || " plus " || b.child || " have the same size: " || s.size  FROM parents AS a, parents AS b, sizes AS s, dogs AS d1, dogs AS d2 WHERE a.parent = b.parent AND a.child < b.child AND d1.name = a.child AND d2.name = b.child AND s.min < d1.height AND d1.height <= max AND s.min < d2.height AND d2.height <= max;
