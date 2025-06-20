# MailStack CLI Mail Client

MailStack is a simple command-line interface (CLI) mail client that allows users to compose, save, read, and delete email messages stored in .mbox-style files. It uses a folder-based structure with Inbox, Sent, and Drafts folders.

## Features

- **Compose**: Create and save new email messages to Drafts.
- **Inbox**: View a list of messages in the inbox.
- **Read**: Display the full content of a message by its ID.
- **Delete**: Delete or archive a message by its ID.

## Directory Structure

    mailstack/
    ├── src/
    │   ├── main.cpp            # CLI logic
    │   ├── mail.cpp            # Parsing, formatting, mail object handling
    │   ├── storage.cpp         # Saving and loading emails
    ├── include/
    │   ├── mail.h              # Mail struct and logic declarations
    │   ├── storage.h           # File I/O function declarations
    ├── data/
    │   ├── inbox.mbox          # Inbox mail file
    │   ├── sent.mbox           # Sent mail file
    │   ├── drafts.mbox         # Draft mail file
    ├── Makefile
    ├── README.md

## Installation

1. Ensure you have `g++` and `make` installed.
2. Clone the repository or copy the files to your project directory.
3. Run `make` in the project root to compile the program.
4. The executable `mailstack` will be generated.

## Usage

Run the program with the following commands:

- `./mailstack compose` - Compose a new email and save it to drafts.
- `./mailstack inbox` - List all emails in the inbox.
- `./mailstack read <id>` - Read the email with the specified ID.
- `./mailstack delete <id>` - Delete the email with the specified ID.

## Notes

- Messages are stored in .mbox-style files in the `data/` directory.
- Each message is assigned a unique ID based on timestamp and a random number.
- The `from` field in emails is currently not set during composition (defaults to empty).

## Limitations

- This is a basic implementation without networking or email sending capabilities.
- Deletion rewrites the entire .mbox file, which may be inefficient for large mailboxes.
- No support for attachments or advanced email features.

## Future Improvements

- Add support for sending emails via SMTP.
- Implement folder management (e.g., move messages between folders).
- Add support for email attachments.
- Improve performance for large .mbox files.

