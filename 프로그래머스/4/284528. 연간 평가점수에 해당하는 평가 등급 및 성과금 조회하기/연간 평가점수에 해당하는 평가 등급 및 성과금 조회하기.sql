-- 코드를 작성해주세요
SELECT A.EMP_NO, EMP_NAME, GRADE,
SAL*(
CASE WHEN GRADE='S' THEN 20
    WHEN GRADE='A' THEN 15
    WHEN GRADE='B' THEN 10
    ELSE 0
END)/100 BONUS
FROM HR_EMPLOYEES A
JOIN ( SELECT EMP_NO,
      (CASE WHEN AVG(SCORE)>=96 THEN 'S'
            WHEN AVG(SCORE)>=90 THEN 'A'
            WHEN AVG(SCORE)>=80 THEN 'B'
            ELSE 'C'
        END) GRADE
      FROM HR_GRADE
      GROUP BY EMP_NO
) B
ON A.EMP_NO=B.EMP_NO
ORDER BY A.EMP_NO