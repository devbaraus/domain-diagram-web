FROM golang:1.23 AS builder

WORKDIR /app

COPY go.mod .

COPY go.sum .

RUN go mod download

COPY . .

RUN go build -o /go/bin/api

FROM gcr.io/distroless/base AS runner

COPY --from=builder /go/bin/api /go/bin/api

CMD ["/go/bin/api"]
