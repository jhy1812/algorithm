-- 코드를 입력하세요
SELECT REST_INFO.REST_ID, REST_NAME, FOOD_TYPE, FAVORITES, ADDRESS, round(avg(REVIEW_SCORE), 2) as SCORE FROM REST_INFO
RIGHT JOIN REST_REVIEW
ON (REST_INFO.REST_ID = REST_REVIEW.REST_ID)
WHERE ADDRESS LIKE '서울%'
GROUP BY REST_NAME
ORDER BY SCORE DESC, FAVORITES DESC;