//
//  LoginViewController.swift
//  Flash Chat iOS13
//
//  Created by Дмитрий Х on 14.09.22.
//

import UIKit
import Firebase

class LoginViewController: UIViewController {
    @IBOutlet weak var emailTextfield: UITextField!
    @IBOutlet weak var passwordTextfield: UITextField!
    @IBAction func loginPressed(_ sender: UIButton) {
        if let email = emailTextfield.text, let password = passwordTextfield.text {
            Auth.auth().signIn(withEmail: email, password: password) { _, error in
                if let safeError = error {
                    func showAlertLogin() {
                        // create the alert
                        let alert = UIAlertController(title: "", message: "\(safeError.localizedDescription)", preferredStyle: UIAlertController.Style.alert)
                        alert.addAction(UIAlertAction(title: "OK", style: UIAlertAction.Style.default, handler: nil))
                        // show the alert
                        self.present(alert, animated: true, completion: nil)
                    }
                    showAlertLogin()
                } else {
                    self.performSegue(withIdentifier: Constants.loginSegue, sender: self)
                }
            }
        }
    }
}
