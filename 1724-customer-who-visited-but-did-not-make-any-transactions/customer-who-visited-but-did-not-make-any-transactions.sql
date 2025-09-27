-- Write your PostgreSQL query statement below
SELECT v.customer_id
     , count(v.customer_id) count_no_trans
  FROM visits v
 WHERE NOT EXISTS (SELECT 1 FROM transactions t WHERE v.visit_id = t.visit_id)
 GROUP BY v.customer_id;