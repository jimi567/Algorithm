SELECT P.PRODUCT_CODE, SUM(P.PRICE * S.SALES_AMOUNT) AS SALES
FROM PRODUCT AS P
JOIN OFFLINE_SALE AS S USING(PRODUCT_ID)
GROUP BY PRODUCT_ID
ORDER BY SALES DESC, P.PRODUCT_CODE
