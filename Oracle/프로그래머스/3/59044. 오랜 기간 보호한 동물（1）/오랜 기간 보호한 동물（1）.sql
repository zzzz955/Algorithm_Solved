-- 코드를 입력하세요
SELECT A.NAME, A.DATETIME
FROM ANIMAL_INS A
LEFT JOIN ANIMAL_OUTS B
ON A.ANIMAL_ID = B.ANIMAL_ID
WHERE 1=1
AND B.DATETIME IS NULL
ORDER BY A.DATETIME
FETCH FIRST 3 ROWS ONLY