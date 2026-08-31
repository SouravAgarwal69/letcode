# Write your MySQL query statement below
select p.product_id, ROUND(
        CASE
            WHEN SUM(u.units) IS NULL THEN 0
            ELSE SUM(p.price * u.units) / SUM(u.units)
        END,
        2
    ) AS average_price from Prices p left join UnitsSold u on p.product_id=u.product_id and u.purchase_date between p.start_date and p.end_date group by p.product_id;
