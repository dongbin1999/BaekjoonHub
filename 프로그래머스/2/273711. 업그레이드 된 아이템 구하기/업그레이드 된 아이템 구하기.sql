SELECT I.ITEM_ID,ITEM_NAME,RARITY
FROM ITEM_INFO I
JOIN(
    SELECT T.ITEM_ID,T.PARENT_ITEM_ID
    FROM ITEM_TREE T
    JOIN ITEM_INFO I
    ON I.ITEM_ID=T.PARENT_ITEM_ID AND RARITY='RARE'
) J
WHERE I.ITEM_ID=J.ITEM_ID
ORDER BY I.ITEM_ID DESC