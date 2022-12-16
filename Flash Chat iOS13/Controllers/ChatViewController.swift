//
//  ChatViewController.swift
//  Flash Chat iOS13
//
//  Created by Дмитрий Х on 14.09.22.
//

import UIKit
import Firebase

class ChatViewController: UIViewController {
    @IBOutlet weak var tableView: UITableView!
    @IBOutlet weak var messageTextfield: UITextField!
    private let dataBase = Firestore.firestore()
    private var messages: [Message] = []
    override func viewDidLoad() {
        super.viewDidLoad()
        tableView.dataSource = self
        title = Constants.appName
        navigationItem.hidesBackButton = true
        tableView.register(UINib(nibName: Constants.cellNibName, bundle: nil), forCellReuseIdentifier: Constants.cellIdentifier)
        loadMessages()
    }
    private func loadMessages() {
        dataBase.collection(Constants.FStore.collectionName).order(by: Constants.FStore.dateField).addSnapshotListener { (querySnapshot, error) in
            self.messages = []
            if let safeError = error {
                Logger.shared.debugPrint("There was an issue retrieving data from Firestore. \(safeError)")
            } else {
                if let snapshotDocuments = querySnapshot?.documents {
                    for docs in snapshotDocuments {
                        let data = docs.data()
                        if let messageSender = data[Constants.FStore.senderField] as? String, let messageBody = data[Constants.FStore.bodyField] as? String {
                            let newMessage = Message(sender: messageSender, body: messageBody)
                            self.messages.append(newMessage)
                            DispatchQueue.main.async {
                                self.tableView.reloadData()
                                let indexPath = IndexPath(row: self.messages.count - 1, section: 0)
                                self.tableView.scrollToRow(at: indexPath, at: .top, animated: false)
                            }
                        }
                    }
                }
            }
        }
    }
    @IBAction func sendPressed(_ sender: UIButton) {
        if messageTextfield.text != "" {
            if let messageBody = messageTextfield.text, let messageSender = Auth.auth().currentUser?.email {
                dataBase.collection(Constants.FStore.collectionName).addDocument(data: [
                    Constants.FStore.senderField: messageSender,
                    Constants.FStore.bodyField: messageBody,
                    Constants.FStore.dateField: Date().timeIntervalSince1970
                ]) { (error) in
                    if let safeError = error {
                        Logger.shared.debugPrint("There was an issue saving data to firestore, \(safeError)")
                    }
                }
                messageTextfield.text = ""
            }
        }
    }
    @IBAction func logOutPressed(_ sender: UIBarButtonItem) {
        do {
            try Auth.auth().signOut()
            navigationController?.popToRootViewController(animated: true)
        } catch let signOutError as NSError {
            Logger.shared.debugPrint("Error signing out: %@ \(signOutError)")
        }
    }
}

extension ChatViewController: UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return messages.count
    }
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let message = messages[indexPath.row]
        let cell = tableView.dequeueReusableCell(withIdentifier: Constants.cellIdentifier, for: indexPath) as? MessageCell
        guard let safeCell = cell else {
            let cell = UITableViewCell(style: .default, reuseIdentifier: Constants.cellIdentifier)
            Logger.shared.debugPrint("Failed to create a cell")
            return cell
        }
        safeCell.label.text = message.body
        // This is a message from current user.
        if message.sender == Auth.auth().currentUser?.email {
            safeCell.leftImageView.isHidden = true
            safeCell.rightImageView.isHidden = false
            safeCell.messageBubble.backgroundColor = UIColor(named: Constants.BrandColors.lightPurple)
            safeCell.label.textColor = UIColor(named: Constants.BrandColors.purple)
        }
        // This is a message from another user.
        else {
            safeCell.leftImageView.isHidden = false
            safeCell.rightImageView.isHidden = true
            safeCell.messageBubble.backgroundColor = UIColor(named: Constants.BrandColors.purple)
            safeCell.label.textColor = UIColor(named: Constants.BrandColors.lightPurple)
        }
        return safeCell
    }
}
