CREATE TABLE [dbo].[GayCounter]
(
	[GayCounterId] INT NOT NULL PRIMARY KEY, 
    [Username] NCHAR(10) NOT NULL, 
    [GayCount] INT NOT NULL DEFAULT 0, 
    [LastIncident] DATETIME NOT NULL
)
