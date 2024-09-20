import { Knex } from "knex";

const config: Knex.Config = {
    client: "pg",
    connection: {
        host: "127.0.0.1",
        user: "postgres",
        password: "password",
        database: "mydb"
    }
};

export default config;
