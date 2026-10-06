# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary FROM EMPLOYEE
WHERE salary <> (
    SELECT MAX(salary) FROM EMPLOYEE
);