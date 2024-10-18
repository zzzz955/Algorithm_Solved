-- 코드를 입력하세요
SELECT F.PRODUCT_ID, F.PRODUCT_NAME, F.PRODUCT_CD, F.CATEGORY, F.PRICE
FROM FOOD_PRODUCT F, (
    SELECT MAX(PRICE) AS MAX_VAL
    FROM FOOD_PRODUCT
) S
WHERE F.PRICE = S.MAX_VAL