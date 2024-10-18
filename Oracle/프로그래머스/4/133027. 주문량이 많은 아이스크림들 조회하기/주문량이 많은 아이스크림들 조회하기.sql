-- 코드를 입력하세요
SELECT FLAVOR
FROM (
SELECT A.FLAVOR, A.TOTAL_ORDER + B.TOTAL_ORDER AS TOTAL_ORDER
FROM FIRST_HALF A
INNER JOIN (
    SELECT FLAVOR, SUM(TOTAL_ORDER) AS TOTAL_ORDER
    FROM JULY
    GROUP BY FLAVOR
) B
ON A.FLAVOR = B.FLAVOR
ORDER BY 2 DESC
)
WHERE ROWNUM <= 3