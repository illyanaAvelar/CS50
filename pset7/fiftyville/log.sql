-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Looking for crime description
SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND year = 2023
AND street = "Humphrey Street";

-- Looking for interviews that mention the bakery
SELECT transcript, month, day
from interviews
WHERE transcript LIKE '%bakery%';

--Looking for license plates that left the parking log within 10 minutes
SELECT license_plate, hour, minute, activity
from bakery_security_logs
WHERE hour = 10 AND minute BETWEEN 15 AND 25
and activity = 'exit';

--Looking for atm transactions from that morning
SELECT account_number, amount
from atm_transactions
WHERE transaction_type = 'withdraw'
AND month = 7 AND day = 28 AND year = 2023
AND atm_location = 'Leggett Street';

--Looking for calls of less then a minute on that day
SELECT caller, receiver
FROM phone_calls
WHERE month = 7 AND day = 28 AND year = 2023
AND duration < 60;

-- Earlier flight on the next day from Fiftyville, with destination
SELECT f.id, f.year, f.month, f.day, f.hour, f.minute, a_dest.full_name AS destination, a_dest.city
FROM flights f
JOIN airports a_origin ON f.origin_airport_id = a_origin.id
JOIN airports a_dest ON f.destination_airport_id = a_dest.id
WHERE f.year = 2023
AND f.month = 7
AND f.day = 29
AND a_origin.city = 'Fiftyville'
ORDER BY f.hour, f.minute
LIMIT 1;

-- Passports from the flight on the next day from Fiftyville
SELECT passport_number
FROM passengers
WHERE flight_id = 36;

-- Finding suspects with personal information on all previous queries
WITH suspects AS (
    SELECT p.id, p.name, p.phone_number, p.passport_number, p.license_plate, b.account_number
    FROM people p
    JOIN bank_accounts b ON p.id = b.person_id
    WHERE p.license_plate IN (
        SELECT license_plate
        FROM bakery_security_logs
        WHERE hour = 10
        AND minute BETWEEN 15 AND 25
        AND activity = 'exit'
    )
    AND b.account_number IN (
        SELECT account_number
        FROM atm_transactions
        WHERE transaction_type = 'withdraw'
        AND month = 7
        AND day = 28
        AND year = 2023
        AND atm_location = 'Leggett Street'
    )
    AND p.phone_number IN (
        SELECT caller
        FROM phone_calls
        WHERE month = 7
        AND day = 28
        AND year = 2023
        AND duration < 60
    )
    AND p.passport_number IN (
        SELECT passport_number
        FROM passengers
        WHERE flight_id = 36
    )
)
SELECT * FROM suspects;

-- Finding the person the suspect called
SELECT *
FROM people
WHERE phone_number = '(375) 555-8161';
