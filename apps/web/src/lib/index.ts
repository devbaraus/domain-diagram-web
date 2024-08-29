// place files you want to import through the `$lib` alias in this folder.
export const grammar =  `
aggregate<UserID> User {
    name: String
    isActive: Boolean
    currentEvaluation: Float
    amount: Int
}

value_object TaskFile {
    filename: String
    updatedAt: Date
}

enum TaskStatus {
    OPEN
    IN_PROGRESS
    DONE
    CANCELED
}

aggregate<TaskGroupID> TaskGroup {
    tasks: TaskID[]
}

aggregate<TeamID> Team {
    name: String
}

entity<TaskID> Task {
    dueDate: Date
    status: TaskStatus
}`;