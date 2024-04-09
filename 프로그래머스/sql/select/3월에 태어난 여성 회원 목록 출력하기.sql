SELECT MP.MEMBER_ID, MP.MEMBER_NAME, MP.GENDER, DATE_FORMAT(MP.DATE_OF_BIRTH,'%Y-%m-%d') AS DATE_OF_BIRTH
FROM MEMBER_PROFILE AS MP
WHERE DATE_FORMAT(MP.DATE_OF_BIRTH,'%m') = '03'
AND MP.GENDER = 'W'
AND MP.TLNO IS NOT NULL 
ORDER BY MEMBER_ID;
