Declare
    rno number(3):=&roll_number;
    bname varchar2(20):='&book_name';
    no_days number(7);
    issuedate date;
    fineamt number(5):=0;
    begin
    select DateofIssue into issuedate from borrower where roll_no=rno;
    select sysdate-to_date(issuedate) days into no_days from dual;
   if(no_days>=15 and no_days<=30) then
   fineamt:=no_days * 5;
   elsif no_days>30 then
   fineamt:=no_days * 50;
   end if;
   update borrower set status='R' where roll_no=rno;
   if fineamt>=0 then
   insert into fine values(rno,sysdate,fineamt);
   end if;
   EXCEPTION
   WHEN no_data_found THEN
   dbms_output.put_line('Record not found');
   end;   
   /
