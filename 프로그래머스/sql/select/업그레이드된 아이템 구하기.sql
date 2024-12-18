SELECT I.ITEM_ID, I.ITEM_NAME, I.RARITY
FROM ITEM_INFO AS I,
  (
SELECT T.ITEM_ID
FROM ITEM_INFO AS I, ITEM_TREE AS T
WHERE I.RARITY = 'RARE'
AND T.PARENT_ITEM_ID = I.ITEM_ID
) AS P
WHERE I.ITEM_ID = P.ITEM_ID
ORDER BY I.ITEM_ID DESC
