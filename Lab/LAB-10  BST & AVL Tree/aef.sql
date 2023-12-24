SET SERVEROUTPUT ON SIZE 1000000
-- Task 1
-- a)
BEGIN
    DBMS_OUTPUT.PUT_LINE('MD Mehedi Al Mahmud');
END;
/

-- b)
DECLARE
    id NUMBER := 1;
BEGIN
    id := &id;
    DBMS_OUTPUT.PUT_LINE(id);
END;
/

-- c)
DECLARE
    num1 NUMBER := 1;
    num2 NUMBER := 1;
BEGIN
    num1 := &num1;
    num2 := &num2;
    DBMS_OUTPUT.PUT_LINE(num1 * num2);
END;
/

-- d)
BEGIN
    DBMS_OUTPUT.PUT_LINE(TO_CHAR(SYSDATE, 'HH:MI:SS AM'));
END;
/

-- e)
DECLARE
    num NUMBER := 1;
BEGIN
    num := &num;
    IF num = ROUND(num) THEN
        DBMS_OUTPUT.PUT_LINE('Whole Number');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Fraction');
    END IF;
END;
/

-- f
CREATE OR REPLACE
PROCEDURE is_composite(num IN NUMBER)
AS BEGIN
    FOR i IN 2 .. SQRT(num) LOOP
        IF MOD(num, i) = 0 THEN
            DBMS_OUTPUT.PUT_LINE('Composite');
            RETURN;
        END IF;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Prime');
END;
/

DECLARE
    num NUMBER := 1;
BEGIN
    num := &num;
    is_composite(num);
END;
/

-- Task 2
-- a)

CREATE OR REPLACE
PROCEDURE top_rated_movies(n IN NUMBER)
AS cnt NUMBER;
BEGIN
    SELECT COUNT(*) INTO cnt FROM movie;
    IF n > cnt THEN
        DBMS_OUTPUT.PUT_LINE('ERROR: insufficient movies');
        RETURN;
    END IF;
    cnt := 0;
    FOR i IN (SELECT m.mov_id, m.mov_title,NVL(r.avg_rating, 0) as avg_rating
            FROM movie m
            LEFT JOIN (SELECT mov_id, AVG(rev_stars) as avg_rating
                    FROM rating
                    GROUP BY mov_id) r
            ON m.mov_id = r.mov_id
            ORDER BY avg_rating DESC
         ) LOOP
        DBMS_OUTPUT.PUT_LINE('ID: ' || i.mov_id|| ', Title: '|| i.mov_title ||', Rating: '|| ROUND(i.avg_rating, 2));
        cnt := cnt + 1;
        EXIT WHEN cnt >= n;
    END LOOP;
END;
/

DECLARE
    n NUMBER := 1;
BEGIN
    n := &n;
    top_rated_movies(n);
END;
/

-- b)

-- titles -- 'Aliens', 'The Theory of Everything';

CREATE OR REPLACE
FUNCTION movie_status(title VARCHAR2)
RETURN VARCHAR2
AS cnt NUMBER;
BEGIN
    SELECT act_cnt INTO cnt
    FROM (SELECT m.mov_id, m.mov_title, c.act_cnt
        FROM movie m
        INNER JOIN (SELECT mov_id, COUNT(*) as act_cnt
                    FROM casts
                    GROUP BY mov_id) c
        ON m.mov_id = c.mov_id)
    WHERE mov_title = title;

    IF cnt = 1 THEN
        RETURN 'Solo';
    ELSE
        RETURN 'Ensemble';
    END IF;
END;
/

DECLARE
    title VARCHAR2(100) := 'title';
BEGIN
    title := '&title';
    DBMS_OUTPUT.PUT_LINE(movie_status(title));
END;
/
