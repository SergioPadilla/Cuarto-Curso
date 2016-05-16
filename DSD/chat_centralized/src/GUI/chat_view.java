package GUI;

import javax.swing.*;
import javax.swing.event.ListDataListener;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by SergioPadilla on 8/5/16.
 */
public class chat_view {
    private JList chat_container;
    private JButton send_action;
    private JTextField message_text;

    private DefaultListModel<String> chat_messages;

    chat_view(){
        send_action.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                show_message();
            }
        });
    }

    public void show_message(){
        String message = message_text.getText();
        chat_messages.addElement(message);
        chat_container.setModel(chat_messages);
    }

    public static void main(String[] args) {

    }
}
