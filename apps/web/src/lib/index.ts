// place files you want to import through the `$lib` alias in this folder.
export const grammar = `// This a placeholder grammar
Aggregate<UserID> User {
    username: String
    email: String
}

Aggregate<TaskID> Task {
    name: String
    description: String?
    tags: String[]
    assignees: UserID[]
    status: TaskStatus
}

ValueObject SomeValueObject {
    filename: String
    updatedAt: Date
}

Enum TaskStatus {
    OPEN
    IN_PROGRESS
    DONE
    CANCELED
}

Entity<SomeEntityID> SomeEntity {
    dueDate: Date
    status: TaskStatus
}
`;

export function getAvatarName(name: string) {
    if (!name) {
        return 'U';
    }

    let res = name.split(' ');

    if (res.length > 1) {
        return res[0][0] + res[1][0];
    }

    return res[0][0] + res[0][1];
}

export function getAvatarColor(name: string) {
    let hash = 0;
    name.split('').forEach((char) => {
        hash = char.charCodeAt(0) + ((hash << 5) - hash);
    });
    let colour = '#';
    for (let i = 0; i < 3; i++) {
        const value = (hash >> (i * 8)) & 0xff;
        colour += value.toString(16).padStart(2, '0');
    }
    return colour;
}