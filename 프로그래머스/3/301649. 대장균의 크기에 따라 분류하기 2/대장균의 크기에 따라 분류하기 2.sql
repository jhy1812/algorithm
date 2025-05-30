SELECT ID,
CASE
WHEN R = 1 THEN 'CRITICAL'
WHEN R = 2 THEN 'HIGH'
WHEN R = 3 THEN 'MEDIUM'
WHEN R = 4 THEN 'LOW'
END AS COLONY_NAME
FROM (
SELECT ID, NTILE(4) OVER(ORDER BY SIZE_OF_COLONY DESC) AS R FROM ECOLI_DATA) AS D
ORDER BY ID ASC
