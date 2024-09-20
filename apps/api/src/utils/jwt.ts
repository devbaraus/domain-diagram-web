import * as jose from 'jose'
import { createSecretKey } from 'crypto';
import { User } from '@prisma/client';

const secretKey = createSecretKey('secret', 'utf-8');


export async function signToken(user: User) {
    return new jose.SignJWT({
        sub: String(user.id),
    }) // details to  encode in the token
        .setProtectedHeader({
            alg: 'HS256'
        }) // algorithm
        .setIssuedAt()
        .setIssuer(process.env.JWT_ISSUER as string) // issuer
        .setAudience(process.env.JWT_AUDIENCE as string) // audience
        .setExpirationTime(process.env.JWT_EXPIRATION_TIME as string) // token expiration time, e.g., "1 day"
        .sign(secretKey); // secretKey generated from previous step
}

export async function verifyToken(token: string) {
    return jose.jwtVerify(token, secretKey, {
        issuer: process.env.JWT_ISSUER as string,
        audience: process.env.JWT_AUDIENCE as string,
    });
}