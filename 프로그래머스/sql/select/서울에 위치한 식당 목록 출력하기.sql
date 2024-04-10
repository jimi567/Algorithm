SELECT I.REST_ID, I.REST_NAME,I.FOOD_TYPE, I.FAVORITES, I.ADDRESS, IFNULL(ROUND(AVG(R.REVIEW_SCORE),2),0) AS SCORE
FROM REST_INFO AS I
JOIN REST_REVIEW AS R ON R.REST_ID = I.REST_ID
WHERE SUBSTRING(I.ADDRESS,1,2) = '서울'  -- LIKE '서울%' 로 해도됨
GROUP BY I.REST_ID
ORDER BY SCORE DESC, I.FAVORITES DESC
