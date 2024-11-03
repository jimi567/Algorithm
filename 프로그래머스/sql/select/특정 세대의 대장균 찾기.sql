//서브쿼리 join으로도 가능할듯
SELECT E3.ID
FROM ECOLI_DATA AS E3
WHERE E3.PARENT_ID IN (SELECT E2.ID 
                     FROM ECOLI_DATA AS E2
                     WHERE E2.PARENT_ID IN (SELECT E1.ID
                                          FROM ECOLI_DATA AS E1
                                          WHERE E1.PARENT_ID IS NULL))
ORDER BY ID                                     
  
