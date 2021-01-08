# Write your MySQL query statement below
select Score, DENSE_RANK() over (ORDER BY Score DESC) as 'Rank' from Scores;
