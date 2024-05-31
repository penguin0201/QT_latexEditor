create database myLatexEditorDataBase;

CREATE TABLE file (
    filename VARCHAR(128) NOT NULL,
    filepath VARCHAR(128) NOT NULL
);

select * from file;

insert into file (id, filename) values ('1', 'file1');

DELETE FROM file WHERE filename = fileName.section('.',0,0);