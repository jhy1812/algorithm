SELECT COUNT(CASE WHEN LENGTH IS NULL THEN ID END) AS FISH_COUNT
FROM FISH_INFO
