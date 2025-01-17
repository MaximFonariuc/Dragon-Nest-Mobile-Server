USE login;

INSERT INTO gateinfo (
    `server_id`, `channel`, `state`, `is_open`, `server_name`, `zone_name`, `ipaddr`, `free_ipaddr`, `register_account`, `online_role`, `open_time`, `full_register_time`, `combine_serverid`, `backflow_level`
) VALUES
    (1, 0, 6, 1, 'Server 1', 'Zone A', '127.0.0.1:10110', '', 100, 10, '2023-10-01 12:00:00', '2023-10-02 14:30:00', 0, 0),
    (2, 0, 6, 1, 'Server 2', 'Zone A', '127.0.0.1:10110', '', 100, 10, '2023-10-01 12:00:00', '2023-10-02 14:30:00', 0, 0),
    (3, 0, 6, 1, 'Server 3', 'Zone A', '127.0.0.1:10110', '', 100, 10, '2023-10-01 12:00:00', '2023-10-02 14:30:00', 0, 0),
    (4, 0, 6, 1, 'Server 4', 'Zone A', '127.0.0.1:10110', '', 100, 10, '2023-10-01 12:00:00', '2023-10-02 14:30:00', 0, 0),
    (5, 0, 6, 1, 'Server 5', 'Zone A', '127.0.0.1:10110', '', 100, 10, '2023-10-01 12:00:00', '2023-10-02 14:30:00', 0, 0),
    (6, 0, 6, 1, 'Server 6', 'Zone A', '127.0.0.1:10110', '', 100, 10, '2023-10-01 12:00:00', '2023-10-02 14:30:00', 0, 0),
	(7, 0, 6, 1, 'Server 7', 'Zone A', '127.0.0.1:10110', '', 100, 10, '2023-10-09 11:00:00', '2023-10-10 20:00:00', 0, 0);

INSERT INTO users (`userid`, `password`) VALUES
    ('Test', '12345');

INSERT INTO selfserver (`userid`, `serverid`, `level`, `time`) VALUES
    ('Test', 1, 10, '2023-10-01 12:00:00');

INSERT INTO gmaccount (`account`) VALUES
    ('gm1');