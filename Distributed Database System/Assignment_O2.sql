clear screen;

SET VERIFY OFF;
SET SERVEROUTPUT ON;

DECLARE
	input_cname COURSE.cname%TYPE := '&Course_Name';
	temp_fname FACULTY.fname%TYPE;
	temp_fname2 FACULTY.fname%TYPE;
	temp_cname COURSE.cname%TYPE;
	temp_cname2 COURSE.cname%TYPE;
	temp_sname STUDENT.sname%TYPE;
	maxCourseNum COURSE.cnum%TYPE;
	minCourseNum COURSE.cnum%TYPE;
	maxStudentNum STUDENT.snum%TYPE;
	minStudentNum STUDENT.snum%TYPE;

BEGIN

	SELECT 
		F.fName into temp_fname
	FROM
		COURSE C INNER JOIN FACULTY F ON C.Fid=F.Fid
	WHERE 
		C.cname = input_cname;
	
	DBMS_OUTPUT.PUT_LINE('The Faculty assigned to this course : ' || '  ' || temp_fname);
	
	
	SELECT min(cnum) into minCourseNum from COURSE;
	SELECT max(cnum) into maxCourseNum from COURSE;
	
	DBMS_OUTPUT.PUT_LINE('Other course(s) taken by ' || temp_fname || ' :');
	FOR i in minCourseNum..maxCourseNum LOOP
		SELECT 
			C.cname, F.fName into temp_cname, temp_fname2
		FROM
			COURSE C INNER JOIN FACULTY F ON C.Fid=F.Fid
		WHERE 
			C.cnum = i;
		
		IF temp_cname != input_cname THEN
			IF temp_fname = temp_fname2 THEN
				DBMS_OUTPUT.PUT_LINE(temp_cname);
			END IF;
		END IF;
	END LOOP;
	
	DBMS_OUTPUT.PUT_LINE('Students enrolled for (' || input_cname || ') Course : ');
	
	FOR ren IN
		(
			SELECT
				S.snum, S.sname , S.major
			FROM
				STUDENT S INNER JOIN ENROLLED E ON S.snum = E.snum
				INNER JOIN COURSE C ON E.cnum = C.cnum
			WHERE 
				C.cname = input_cname 
		)
		
	LOOP		
		DBMS_OUTPUT.PUT_LINE(ren.snum || '  ' || ren.sname || '  ' ||ren.major); 
	END LOOP;

EXCEPTION 
	WHEN no_data_found THEN 
		dbms_output.put_line('No Data Available!'); 
END;
/ 