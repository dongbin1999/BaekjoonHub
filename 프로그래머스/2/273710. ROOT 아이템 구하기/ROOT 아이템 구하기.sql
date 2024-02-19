-- 코드를 작성해주세요
SELECT ITEM_ID,ITEM_NAME
FROM ITEM_INFO I
JOIN(
    SELECT ITEM_ID ID
    FROM ITEM_TREE T
    WHERE PARENT_ITEM_ID IS NULL
) J
ON I.ITEM_ID=J.ID
ORDER BY ITEM_ID