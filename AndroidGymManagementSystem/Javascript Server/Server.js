const express = require('express');
const server = express();
const morgan = require('morgan');
const mysql = require('mysql');
const bodyParser = require('body-parser');
const joi = require('@hapi/joi')
const bcrypt = require('bcryptjs')
const jwt = require('jsonwebtoken')
const dotenv = require('dotenv')
const crypto = require('crypto')
server.use(bodyParser.urlencoded({extended: false}));
server.use(bodyParser.json());
server.use(morgan('short'));



/////////////////////////////////////////////////////////////////////REST REQUESTS////////////////////////////////////////////////////////////////////////////////

server.get("/", (req, res) => { //req = request, res = response (JSON objects probably)
    console.log("\nServer Ping\n")
    res.send("ROOT ROUTE")
})

server.get("/testDatabaseQuery", (req, res) => {

    sqlQuery("INSERT INTO Person (EmergencyContactPhone, PersonGymID, Phone, Street, City, ProvState, Postal, TFlag, MFlag) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)", 
    ["5879664481", "12345", "4039936639", "13 Shawbrooke Close SW", "Calgary", "Alberta", "T2Y3A2", "0", "1"], (err, rows) => {
        if(err != null){
            return res.send(err);
        }
        else{
            return res.send("Success");
        }
    })

})

server.post("/person/insert", (req, res) => {
    console.log("\nsuccessfully made request\n");
})



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////HELPER FUNCTIONS /////////////////////////////////////////////////////////////////////////

function sqlQuery(query, arguments, callback){
	getConnection().query(query, arguments, (err, rows, fields) => {

		if(err != null){
			callback(err, null)
		}
		
		callback(null, rows)
	})
}

 const pool = mysql.createPool({ //connection pool 
	 connectionLimit: 10,
	 host: 'localhost',
   	 user: 'root',
	 password: 'Gmcia330@', //look into how to store as system variable
	 database: 'cpsc471gymmanagementsystemschema'
 })
 
 function getConnection(){
	 return pool
 }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



server.listen(3003 /*Look into how to store as system variable*/, () => {
    console.log("Server running on port 3003")
})