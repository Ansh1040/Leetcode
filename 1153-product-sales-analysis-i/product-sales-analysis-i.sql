-- Write your PostgreSQL query statement below
SELECT P.product_name,s.year,s.price 
FROM Sales s JOIN Product p 
ON p.product_id = s.product_id
ORDER BY product_name