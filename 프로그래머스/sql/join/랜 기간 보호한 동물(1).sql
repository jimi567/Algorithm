SELECT I.NAME, I.DATETIME 
FROM ANIMAL_INS AS I
LEFT JOIN ANIMAL_OUTS AS O USING(ANIMAL_ID)
WHERE I.ANIMAL_ID IS NOT NULL AND O.ANIMAL_ID IS NULL
ORDER BY I.DATETIME
LIMIT 3
